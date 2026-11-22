// func malloc @ 00407cf0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_007590f8)();
  return pvVar1;
}

