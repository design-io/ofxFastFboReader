#pragma once
#include "ofMain.h"

#ifndef OFX_FAST_FBO_READER_INCLUDED
    #define OFX_FAST_FBO_READER_INCLUDED
#endif

class ofxFastFboReader {
public:
	
	ofxFastFboReader(const int num_buffers = 3);
	~ofxFastFboReader();
	
	bool readToPixels(ofFbo &fbo, ofPixels& pix, ofImageType type = OF_IMAGE_COLOR);
    bool readToPixels(ofFbo &fbo, ofFloatPixels& pix, int aGlType );
	
	bool getAsync() { return async; }
	void setAsync(bool v) { async = v; }
	
protected:
	
	const int num_buffers;
	
	GLuint *pboIds;
	int index, nextIndex;
	size_t num_bytes = 0;
	bool async;
	
	ofxFastFboReader(const ofxFastFboReader&);
	ofxFastFboReader& operator=(const ofxFastFboReader&);
	
	void genPBOs();
	void setupPBOs(int num_bytes);
	
};
