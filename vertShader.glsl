#version 430
void main(void)
{
	if(gl_VertexID==0){
	gl_Position=vec4(0.5,-0.5,0.0,1.0);
	}
	else if(gl_VertexID==1){
	gl_Position=vec4(-0.5,-0.5,0.0,1.0);
	}

	else {
	gl_Position=vec4(0.0,1.0,0.0,1.0);
	}

	//BC and AC 1.58 ISOSCELES TRIANGLE
	//formula AB = sqrt((A.x-B.x)^2+(A.y-B.y)^2)
}