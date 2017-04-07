#ifndef _VoiceMain_h_
#define _VoiceMain_h_
class VoiceMain
{
public:
	VoiceMain();
	~VoiceMain();


	//static void show_result(char *string, char is_over);
	//static void show_key_hints(void);
	//static int upload_userwords();
	//static unsigned int  __stdcall helper_thread_proc(void * para);
	//static HANDLE start_helper_thread();
	//void on_result(const char *result, char is_last);
	//void on_speech_begin();
	//void on_speech_end(int reason);
	//static void demo_file(const char* audio_file, const char* session_begin_params);
	//static void demo_mic(const char* session_begin_params);
	static void MyMain();
	static void MyStart();
	static void MyStop();
	static char* MyEnd();
};
#endif