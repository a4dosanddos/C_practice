#include "Sample.h"

JNIEXPORT jstring JNICALL Java_Sample_sample
  (JNIEnv *env, jobject thisj, jstring srcj)
{
  printf("call sample()\n");
  return NULL;
}
