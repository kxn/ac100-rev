// func accrypt_des_decrypt @ 00666c94 size=744

size_t accrypt_des_decrypt(int param_1,uint param_2,undefined4 *param_3)

{
  void *__s;
  uint uVar1;
  int iVar2;
  void *__s_00;
  char *pcVar3;
  undefined4 uVar4;
  size_t sVar5;
  undefined1 auStack_98 [16];
  undefined1 auStack_88 [108];
  
  if (g_accrypt_debug != 0) {
    printf("[ACCRYPT_DEBUG]%s()/%05d: input buffer size:%d\r\n","accrypt_des_decrypt",0x136,param_2)
    ;
  }
  if ((param_1 == 0) || (param_2 < 0x10)) {
    if (g_accrypt_error == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[ACCRYPT_ERROR]%s()/%05d: input buffer error.\r\n";
    uVar4 = 0x13b;
  }
  else if (param_3 == (undefined4 *)0x0) {
    if (g_accrypt_error == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[ACCRYPT_ERROR]%s()/%05d: output buffer error.\r\n";
    uVar4 = 0x140;
  }
  else {
    sVar5 = param_2 + 8;
    __s = malloc(sVar5);
    if (__s != (void *)0x0) {
      memset(__s,0,sVar5);
      uVar1 = tpcom_des_min_do(param_1,param_2,__s,sVar5,&DAT_0071ced0,0);
      if (g_accrypt_debug != 0) {
        printf("[ACCRYPT_DEBUG]%s()/%05d: des decrypt return:%d\r\n","accrypt_des_decrypt",0x156,
               uVar1);
      }
      if (uVar1 < 0x10) {
        if (g_accrypt_error != 0) {
          printf("[ACCRYPT_ERROR]%s()/%05d: size of des decrypt file is too small[%d/%d].\r\n",
                 "accrypt_des_decrypt",0x159,uVar1,0x10);
        }
      }
      else {
        sVar5 = uVar1 - 0x10;
        if (g_accrypt_debug != 0) {
          printf("[ACCRYPT_DEBUG]%s()/%05d: string length of raw data:%d\r\n","accrypt_des_decrypt",
                 0x161,sVar5);
        }
        FUN_00408590(auStack_88);
        FUN_00408670(auStack_88,(void *)((int)__s + 0x10),sVar5);
        FUN_00407e90(auStack_98,auStack_88);
        iVar2 = memcmp(auStack_98,__s,0x10);
        if (iVar2 == 0) {
          __s_00 = malloc(sVar5);
          *param_3 = __s_00;
          if (__s_00 != (void *)0x0) {
            memset(__s_00,0,sVar5);
            memcpy((void *)*param_3,(void *)((int)__s + 0x10),sVar5);
            free(__s);
            return sVar5;
          }
          if (g_accrypt_error == 0) goto LAB_00666da4;
          pcVar3 = "[ACCRYPT_ERROR]%s()/%05d: malloc failed.\r\n";
          uVar4 = 0x184;
        }
        else {
          if (g_accrypt_error == 0) goto LAB_00666da4;
          pcVar3 = "[ACCRYPT_ERROR]%s()/%05d: des decrypt failed: md5 dismatch.\r\n";
          uVar4 = 0x179;
        }
        printf(pcVar3,"accrypt_des_decrypt",uVar4);
      }
LAB_00666da4:
      free(__s);
      return 0xffffffff;
    }
    if (g_accrypt_error == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[ACCRYPT_ERROR]%s()/%05d: malloc failed.\r\n";
    uVar4 = 0x149;
  }
  printf(pcVar3,"accrypt_des_decrypt",uVar4);
  return 0xffffffff;
}

