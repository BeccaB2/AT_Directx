struct VSOut
{
	float3 colour : Colour;
	float4 pos : SV_Position;
};

// For use of the constant buffer
cbuffer CBuf
{
	matrix transform;
};

VSOut main(float2 pos : Position, float3 colour : Colour)
{
	VSOut vso;
	vso.pos = mul(float4(pos.x, pos.y, 0.0, 1.0f), transform);
	vso.colour = colour;
	return vso;
}