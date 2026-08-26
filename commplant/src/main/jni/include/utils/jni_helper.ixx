module;

#include "utils/jni_helper.hpp"

export module jni_helper;

export {
    using ::jboolean;
    using ::jbooleanArray;
    using ::jbyte;
    using ::jbyteArray;
    using ::jchar;
    using ::jcharArray;
    using ::jclass;
    using ::jdouble;
    using ::jdoubleArray;
    using ::jfieldID;
    using ::jfloat;
    using ::jfloatArray;
    using ::jint;
    using ::jintArray;
    using ::jlong;
    using ::jlongArray;
    using ::jmethodID;
    using ::JNIEnv;
    using ::jobject;
    using ::jobjectArray;
    using ::jshort;
    using ::jshortArray;
    using ::jsize;
    using ::jstring;
    using ::jthrowable;
    using ::jvalue;
}

export namespace commplant {
using commplant::JNIMonitor;
using commplant::JNIScopeFrame;
using commplant::JUTFString;
using commplant::ScopedLocalRef;

using commplant::UnwrapScope;
using commplant::WrapScope;

using commplant::JNI_GetBooleanField;
using commplant::JNI_GetByteField;
using commplant::JNI_GetCharField;
using commplant::JNI_GetDoubleField;
using commplant::JNI_GetFieldID;
using commplant::JNI_GetFloatField;
using commplant::JNI_GetIntField;
using commplant::JNI_GetLongField;
using commplant::JNI_GetObjectField;
using commplant::JNI_GetShortField;
using commplant::JNI_SetBooleanField;
using commplant::JNI_SetByteField;
using commplant::JNI_SetCharField;
using commplant::JNI_SetDoubleField;
using commplant::JNI_SetFloatField;
using commplant::JNI_SetIntField;
using commplant::JNI_SetLongField;
using commplant::JNI_SetObjectField;
using commplant::JNI_SetShortField;

using commplant::JNI_GetStaticBooleanField;
using commplant::JNI_GetStaticByteField;
using commplant::JNI_GetStaticCharField;
using commplant::JNI_GetStaticDoubleField;
using commplant::JNI_GetStaticFieldID;
using commplant::JNI_GetStaticFloatField;
using commplant::JNI_GetStaticIntField;
using commplant::JNI_GetStaticLongField;
using commplant::JNI_GetStaticObjectField;
using commplant::JNI_GetStaticShortField;
using commplant::JNI_SetStaticBooleanField;
using commplant::JNI_SetStaticByteField;
using commplant::JNI_SetStaticCharField;
using commplant::JNI_SetStaticDoubleField;
using commplant::JNI_SetStaticFloatField;
using commplant::JNI_SetStaticIntField;
using commplant::JNI_SetStaticLongField;
using commplant::JNI_SetStaticObjectField;
using commplant::JNI_SetStaticShortField;

using commplant::JNI_CallBooleanMethod;
using commplant::JNI_CallByteMethod;
using commplant::JNI_CallCharMethod;
using commplant::JNI_CallDoubleMethod;
using commplant::JNI_CallFloatMethod;
using commplant::JNI_CallIntMethod;
using commplant::JNI_CallLongMethod;
using commplant::JNI_CallNonvirtualBooleanMethod;
using commplant::JNI_CallNonvirtualByteMethod;
using commplant::JNI_CallNonvirtualCharMethod;
using commplant::JNI_CallNonvirtualDoubleMethod;
using commplant::JNI_CallNonvirtualFloatMethod;
using commplant::JNI_CallNonvirtualIntMethod;
using commplant::JNI_CallNonvirtualLongMethod;
using commplant::JNI_CallNonvirtualObjectMethod;
using commplant::JNI_CallNonvirtualShortMethod;
using commplant::JNI_CallNonvirtualVoidMethod;
using commplant::JNI_CallObjectMethod;
using commplant::JNI_CallShortMethod;
using commplant::JNI_CallStaticBooleanMethod;
using commplant::JNI_CallStaticByteMethod;
using commplant::JNI_CallStaticCharMethod;
using commplant::JNI_CallStaticDoubleMethod;
using commplant::JNI_CallStaticFloatMethod;
using commplant::JNI_CallStaticIntMethod;
using commplant::JNI_CallStaticLongMethod;
using commplant::JNI_CallStaticObjectMethod;
using commplant::JNI_CallStaticShortMethod;
using commplant::JNI_CallStaticVoidMethod;
using commplant::JNI_CallVoidMethod;
using commplant::JNI_GetMethodID;
using commplant::JNI_GetStaticMethodID;
using commplant::JNI_ToReflectedMethod;
using commplant::JNI_ToReflectedField;

using commplant::JNI_NewBooleanArray;
using commplant::JNI_NewByteArray;
using commplant::JNI_NewCharArray;
using commplant::JNI_NewDirectByteBuffer;
using commplant::JNI_NewDoubleArray;
using commplant::JNI_NewFloatArray;
using commplant::JNI_NewIntArray;
using commplant::JNI_NewLongArray;
using commplant::JNI_NewObject;
using commplant::JNI_NewObjectArray;
using commplant::JNI_NewShortArray;

using commplant::JNI_Cast;
using commplant::JNI_FindClass;
using commplant::JNI_GetArrayLength;
using commplant::JNI_GetObjectClass;
using commplant::JNI_GetObjectFieldOf;
using commplant::JNI_IsInstanceOf;
using commplant::JNI_IsSameObject;
using commplant::JNI_NewGlobalRef;
using commplant::JNI_NewStringUTF;
using commplant::JNI_RegisterNatives;
}  // namespace commplant
