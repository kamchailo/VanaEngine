#include "pch.h"
#include "NodeFactory.h"
#include <fstream>
#include <nlohmann/json.hpp>

const std::string NODE_ROOT = "root";
const std::string NODE_CHILDREN = "Children";
const std::string NODE_BODY_2D = "Body2D";
const std::string NODE_SPRITE = "Sprite";
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

    //std::cout << "json size : " << jsonObj.size() << " json content : " << jsonObj << std::endl;
    //std::cout << "json ['root'] : " << jsonObj[NODE_ROOT][NODE_CHILDREN][0] << std::endl;
    

    //std::string* children = jsonObj["root"]["Children"];

    std::string childrenStr = "/" + NODE_ROOT + "/" + NODE_CHILDREN;

    nlohmann::json children = jsonObj[nlohmann::json::json_pointer(childrenStr)];

    //std::cout << "jsonObj[" << childrenStr << "] : " << children << std::endl;

    AttachTree(*root, children);
    
    return *root;
}

void NodeFactory::AttachTree(Vana::Node& root, nlohmann::json const& children)
{
    for (int i = 0; i < children.size(); ++i)
    {
        std::cout << "begin() : " << children[i].begin().key() << std::endl;

        // Build Body2D
        if (children[i].begin().key() == NODE_BODY_2D)
        {
            nlohmann::json::const_reference body2D = children[i][NODE_BODY_2D];
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
            if (body2D[POSITION] != NULL)
            {
                float posX = body2D[POSITION][0];
                float posY = body2D[POSITION][1];
                float posZ = body2D[POSITION][2];
                std::cout << "POSITION : " << posX << ", " << posY << ", " << posZ << std::endl;
                node->SetPosition(glm::vec3(posX, posY, posZ));
            }
            
            // Rotation
            if (body2D[ROTATION] != NULL )
            {
                float rotX = body2D[ROTATION][0];
                float rotY = body2D[ROTATION][1];
                float rotZ = body2D[ROTATION][2];
                std::cout << "ROTATION : " << rotX << ", " << rotY << ", " << rotZ << std::endl;
                node->SetRotation(glm::vec3(rotX, rotY, rotZ));
            }

            // Scale    
            if (body2D[ROTATION] != NULL)
            {
                float scaleX = body2D[SCALE][0];
                float scaleY = body2D[SCALE][1];
                float scaleZ = body2D[SCALE][2];
                std::cout << "SCALE : " << scaleX << ", " << scaleY << ", " << scaleZ << std::endl;
                node->SetScale(glm::vec3(scaleX, scaleY, scaleZ));
            }

            // Width Height    
            float width;
            if (body2D[WIDTH] != NULL)
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
            if (body2D[HEIGHT] != NULL)
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
            if (body2D[TEXTURE] != NULL)
            {
                textureLoc = body2D[TEXTURE];
                std::cout << "TEXTURE : " << textureLoc << std::endl;
            }
            else
            {
                //vana_default_texture.png
                textureLoc = "default/vana_default_texture.png";
            }
            texture = new Texture(textureLoc.c_str(), FALSE);

            // Build Renderer and PhysicsBody
            ComponentTransform* compTransform = new ComponentTransform();
            ComponentRenderer* compRenderer = new ComponentRenderer(texture, glm::vec2(width, height));
            ComponentPhysics* compPhysics = new ComponentPhysics(Vana::collisionManager, glm::vec2(width, height), 3, 4);
                
            node->AddComponent(compTransform);
            node->AddComponent(compRenderer);
            node->AddComponent(compPhysics);

            if (body2D[NODE_CHILDREN].size() > 0)
            {
                AttachTree(*node, body2D[NODE_CHILDREN]);
            }
        }

        // Build Sprite
        else if (children[i].begin().key() == NODE_SPRITE)
        {
        nlohmann::json::const_reference sprite = children[i][NODE_SPRITE];
        std::cout << "Children[" << i << "] : " << sprite << std::endl;

        Vana::Node* node;

        // Name
        if (sprite[NAME].is_null())
        {
            std::string node_name = sprite[NAME];
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
        if (sprite[POSITION] != NULL)
        {
            float posX = sprite[POSITION][0];
            float posY = sprite[POSITION][1];
            float posZ = sprite[POSITION][2];
            std::cout << "POSITION : " << posX << ", " << posY << ", " << posZ << std::endl;
            node->SetPosition(glm::vec3(posX, posY, posZ));
        }

        // Rotation
        if (sprite[ROTATION] != NULL)
        {
            float rotX = sprite[ROTATION][0];
            float rotY = sprite[ROTATION][1];
            float rotZ = sprite[ROTATION][2];
            std::cout << "ROTATION : " << rotX << ", " << rotY << ", " << rotZ << std::endl;
            node->SetRotation(glm::vec3(rotX, rotY, rotZ));
        }

        // Scale    
        if (sprite[ROTATION] != NULL)
        {
            float scaleX = sprite[SCALE][0];
            float scaleY = sprite[SCALE][1];
            float scaleZ = sprite[SCALE][2];
            std::cout << "SCALE : " << scaleX << ", " << scaleY << ", " << scaleZ << std::endl;
            node->SetScale(glm::vec3(scaleX, scaleY, scaleZ));
        }

        // Width Height    
        float width;
        if (sprite[WIDTH] != NULL)
        {
            width = sprite[WIDTH];
            std::cout << "WIDTH : " << width << std::endl;
        }
        else
        {
            width = 100.0f;
        }
        // Height
        float height;
        if (sprite[HEIGHT] != NULL)
        {
            height = sprite[HEIGHT];
            std::cout << "HEIGHT : " << height << std::endl;
        }
        else
        {
            height = 100.0f;
        }

        // Texture
        std::string textureLoc;
        Texture* texture;
        if (sprite[TEXTURE] != NULL)
        {
            textureLoc = sprite[TEXTURE];
            std::cout << "TEXTURE : " << textureLoc << std::endl;
        }
        else
        {
            //vana_default_texture.png
            textureLoc = "default/vana_default_texture.png";
        }
        texture = new Texture(textureLoc.c_str(), FALSE);

        // Build Renderer and PhysicsBody
        ComponentTransform* compTransform = new ComponentTransform();
        ComponentRenderer* compRenderer = new ComponentRenderer(texture, glm::vec2(width, height));

        node->AddComponent(compTransform);
        node->AddComponent(compRenderer);
        }
    }
}
