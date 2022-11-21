#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;

uniform vec2 uniform_tilling;
uniform vec2 uniform_tillingOffset;

void main()
{
	// uv.a / columns
	// uv.b / rows
	// vec2 uv = vec2(TexCoord.x * 0.25, TexCoord.y * 1);
	// uv = vec2(uv.x + 0.25, uv.y);
	vec2 uv = TexCoord * uniform_tilling;
	uv += uniform_tillingOffset;
	// vec2 uv = TexCoord;
	FragColor = texture(texture1, uv) * vec4(ourColor, 1.0);
}