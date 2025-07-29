#include "FlareShader.h"


IMPLEMENT_GLOBAL_SHADER(FCustomFlareVS, "/GBufferTest/Flare.usf", "FlareVS", SF_Vertex);
IMPLEMENT_GLOBAL_SHADER(FCustomFlarePS, "/GBufferTest/Flare.usf", "FlarePS", SF_Pixel);