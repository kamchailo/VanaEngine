#include "pch.h"
#include "NodeFactory.h"
#include <fstream>
#include <nlohmann/json.hpp>

const std::string NODE_ROOT = "root";
const std::string NODE_CHILDREN = "Children";
const std::string BODY_2D = "Body2D";
const std::string NAME = "Name";
const std::string POSITION = "Position";
const std::string ROTATION = "Rotation";
const std::string SCALE = "Scale";
const std::string WIDTH = "Width";
const std::string HEIGHT = "Height";
const std::string TEXTURE = "Texture";


NodeFactory::NodeFactory()
{
}

NodeFactory::~NodeFactory()
{
    for (auto n : nodes)
    {
        delete n.second;
    }
}

Vana::Node& NodeFactory::CreateScene(std::string _filename)
{
    Vana::Node* root = new Vana::Node();

    std::ifstream f(_filename);
    if (!f)
    {
        std::cout << "Error Openning JSON File." << std::endl;
        return *root;
    }
    
    nlohmann::json jsonObj = nlohmann::json::parse(f);
    f.close();

    std::cout << "json size : " << jsonObj.size() << " json content : " << jsonObj << std::endl;
    std::cout << "json ['root'] : " << jsonObj[NODE_ROOT][NODE_CHILDREN][0] << std::endl;
    

    //std::string* children = jsonObj["root"]["Children"];

    std::string childrenStr = "/" + NODE_ROOT + "/" + NODE_CHILDREN;

    nlohmann::json children = jsonObj[nlohmann::json::json_pointer(childrenStr)];

    std::cout << "jsonObj[" << childrenStr << "] : " << children << std::endl;

    AttachTree(*root, children);
    
    return *root;
}

void NodeFactory::AttachTree(Vana::Node& root, nlohmann::json const& children)
{
    for (int i = 0; i < children.size(); ++i)
    {
        // Build Body2D
        if (children[i][BODY_2D] != NULL)
        {
            nlohmann::json::const_reference body2D = children[i][BODY_2D];
            std::cout << "Children[" << i << "] : " << body2D << std::endl;
            
            Vana::Node* node;
            
            // Name
            if (body2D[NAME].is_null())
            {
                std::string node_name = body2D[NAME];
                std::cout << "NAME : " << node_name << std::endl;
                if (node_name.length() > 0)
                {
                    node = new Vana::Node(node_name, &root);
                }
                else
                {
                    node = new Vana::Node(&root);
                }
            }
            else
            {
                node = new Vana::Node(&root);
            }

            // Position
            if (!body2D[POSITION].is_null())
            {
                float posX = body2D[POSITION][0];
                float posY = body2D[POSITION][1];
                float posZ = body2D[POSITION][2];
                std::cout << "POSITION : " << posX << ", " << posY << ", " << posZ << std::endl;
                node->SetPosition(glm::vec3(posX, posY, posZ));
            }
            
            // Rotation
            if (!body2D[ROTATION].is_null())
            {
                float rotX = body2D[ROTATION][0];
                float rotY = body2D[ROTATION][1];
                float rotZ = body2D[ROTATION][2];
                std::cout << "ROTATION : " << rotX << ", " << rotY << ", " << rotZ << std::endl;
                node->SetRotation(glm::vec3(rotX, rotY, rotZ));
            }

            // Scale    
            if (!body2D[ROTATION].is_null())
            {
                float scaleX = body2D[SCALE][0];
                float scaleY = body2D[SCALE][1];
                float scaleZ = body2D[SCALE][2];
                std::cout << "SCALE : " << scaleX << ", " << scaleY << ", " << scaleZ << std::endl;
                node->SetScale(glm::vec3(scaleX, scaleY, scaleZ));
            }

            // Width Height    
            float width;
            if (!body2D[WIDTH].is_null())
            {
                width = body2D[WIDTH];
                std::cout << "WIDTH : " << width << std::endl;
            }
            else
            {
                width = 100.0f;
            }
            // Height
            float height;
            if (!body2D[HEIGHT].is_null())
            {
                height = body2D[HEIGHT];
                std::cout << "HEIGHT : " << height << std::endl;
            }
            else
            {
                height = 100.0f;
            }

            // Texture
            std::string textureLoc;
            Texture* texture;
            if (!body2D[TEXTURE].is_null())
            {
                textureLoc = body2D[TEXTURE];
                std::cout << "TEXTURE : " << textureLoc << std::endl;
            }
            else
            {
                //vana_default_texture.png
                textureLoc = "default/vana_default_texture.png";
            }
            texture = new Texture(textureLoc.c_str());



            // Build Renderer and PhysicsBody
            ComponentTransform* compTransform = new ComponentTransform();
            ComponentRenderer* compRenderer = new ComponentRenderer(texture, glm::vec2(width, height));
            ComponentPhysics* compPhysics = new ComponentPhysics(Vana::collisionManager, glm::vec2(width, height));
                
            node->AddComponent(compTransform);
            node->AddComponent(compRenderer);
            node->AddComponent(compPhysics);
        }

        /*
        ComponentTransform* trnfA = new ComponentTransform();
	    ComponentRenderer* rendA = new ComponentRenderer(tex, glm::vec2(100, 100));
	    ComponentPhysics* physA = new ComponentPhysics(Vana::collisionManager, glm::vec2(100, 100));
	    nodeA->AddComponent(trnfA);
	    nodeA->AddComponent(rendA);
	    nodeA->AddComponent(physA);
	    nodeA->SetPosition(glm::vec3(-200, 100, 0.0));
        
        
        */
        //Vana::Node* child = new Vana::Node(children[i]["Name"], root);
        // init node
        // attach to root
        // Attatch(node, children['Children])
        /*
        "Body2D" :
        {
          "Name" : "n1",
          "Position" : [-100,100,0],
          "Rotation" : [0,0,0],
          "Scale" : [1,1,1],
          "Width" : 100,
          "height" : 100
        }
        */
    }
}
