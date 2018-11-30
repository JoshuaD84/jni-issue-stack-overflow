#include <jni.h> 

int main() {
   JavaVM *jvm; 
   JNIEnv *env;
   JavaVMInitArgs vm_args; 
   JavaVMOption* options = new JavaVMOption[1];
   
   int index = 0;
   options[index].optionString = (char *)"-Djava.class.path=./main.jar";

   vm_args.version = JNI_VERSION_10;
   vm_args.nOptions = 1;
   vm_args.options = options;
   vm_args.ignoreUnrecognized = false;
   JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
   delete options;

   jmethodID main = NULL;
   jclass cls = NULL;
   
   cls = env->FindClass("net/joshuad/test/Main");
   if(env->ExceptionCheck()) {  
      env->ExceptionDescribe();
      env->ExceptionClear();
   }

   if (cls != NULL) {
      main = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
   } else {
      printf("Unable to find the requested class\n");
   }

   if (main != NULL) {
      env->CallStaticVoidMethod( cls, main, " ");
   } else {
      printf("main method not found") ;
   }

   jvm->DestroyJavaVM();
   return 0;
}

