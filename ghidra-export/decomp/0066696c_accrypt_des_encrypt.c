// func accrypt_des_encrypt @ 0066696c size=808

uint accrypt_des_encrypt(void *param_1,size_t param_2,undefined4 *param_3)

{
  void *__s;
  void *__s_00;
  void *__s_01;
  char *__format;
  undefined4 uVar1;
  uint uVar2;
  size_t __size;
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [108];
  
  if (param_1 == (void *)0x0) {
    if (g_accrypt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACCRYPT_ERROR]%s()/%05d: input buffer error.\r\n";
    uVar1 = 0xad;
LAB_00666b3c:
    printf(__format,"accrypt_des_encrypt",uVar1);
    return 0xffffffff;
  }
  if (param_3 == (undefined4 *)0x0) {
    if (g_accrypt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACCRYPT_ERROR]%s()/%05d: output buffer error.\r\n";
    uVar1 = 0xb2;
    goto LAB_00666b3c;
  }
  uVar2 = param_2 + 0x10;
  __s = malloc(uVar2);
  if (__s == (void *)0x0) {
    if (g_accrypt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACCRYPT_ERROR]%s()/%05d: malloc failed.\r\n";
    uVar1 = 0xbb;
    goto LAB_00666b3c;
  }
  memset(__s,0,uVar2);
  __size = ((uVar2 >> 3) + 2) * 8;
  if (g_accrypt_debug != 0) {
    printf("[ACCRYPT_DEBUG]%s()/%05d: encrypt file length:%d\r\n","accrypt_des_encrypt",0xc1,__size)
    ;
  }
  __s_00 = malloc(__size);
  if (__s_00 == (void *)0x0) {
    if (g_accrypt_error == 0) goto LAB_00666aa8;
    uVar1 = 0xc5;
  }
  else {
    memset(__s_00,0,__size);
    if (g_accrypt_debug != 0) {
      printf("[ACCRYPT_DEBUG]%s()/%05d: input file length:%d\r\n","accrypt_des_encrypt",0xcc,param_2
            );
    }
    FUN_00408590(auStack_90);
    FUN_00408670(auStack_90,param_1,param_2);
    FUN_00407e90(auStack_a0,auStack_90);
    memcpy(__s,auStack_a0,0x10);
    memcpy((void *)((int)__s + 0x10),param_1,param_2);
    uVar2 = tpcom_des_min_do(__s,uVar2,__s_00,__size,&DAT_0071ced0,1);
    if (g_accrypt_debug != 0) {
      printf("[ACCRYPT_DEBUG]%s()/%05d: size of des encrypt file:%d\r\n","accrypt_des_encrypt",0xea,
             uVar2);
    }
    if (uVar2 < 0x10) {
      if (g_accrypt_error != 0) {
        printf("[ACCRYPT_ERROR]%s()/%05d: des encrypt failed:%d.\r\n","accrypt_des_encrypt",0xee,
               uVar2);
      }
      goto LAB_00666aa8;
    }
    __s_01 = malloc(uVar2);
    *param_3 = __s_01;
    if (__s_01 != (void *)0x0) {
      memset(__s_01,0,uVar2);
      memcpy((void *)*param_3,__s_00,uVar2);
      free(__s);
      free(__s_00);
      return uVar2;
    }
    if (g_accrypt_error == 0) goto LAB_00666aa8;
    uVar1 = 0xf7;
  }
  printf("[ACCRYPT_ERROR]%s()/%05d: malloc failed.\r\n","accrypt_des_encrypt",uVar1);
LAB_00666aa8:
  free(__s);
  if (__s_00 != (void *)0x0) {
    free(__s_00);
  }
  return 0xffffffff;
}

