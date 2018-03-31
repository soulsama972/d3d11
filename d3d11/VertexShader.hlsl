struct d {
	float4 pos : SV_POSITION;
	float4 c :COLOR;
};



d Squre(float4 pos : POSITION ,float4 c :COLOR) {

	d output;
	 output.pos = pos;
	 output.c = c;
	 return output;
}


d Line(float3 pos : POSITION, float4 c : COLOR) {

	d output;
	output.pos = float4(pos,1);
	output.c = c;
	return output;
}