// func systime_init @ 0066656c size=264

undefined4 systime_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  systime_register_list = FUN_00408450(0xc,0x87);
  if (systime_register_list == 0) {
    if (g_systime_error == 0) goto LAB_006665f0;
    __format = "[SYSTIME_ERROR] %32s() %05d: malloc failed.\r\n";
    uVar2 = 0x89;
  }
  else {
    FUN_0051ad88(systime_register_list);
    iVar1 = FUN_004084d0("systime",2,systime_jcs_callback_systime_set);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_systime_error != 0) {
      printf("[SYSTIME_ERROR] %32s() %05d: register callback to jcs failed.\r\n",
             "systime_jcs_callback_init",0x6f);
    }
    if (g_systime_error == 0) goto LAB_006665f0;
    __format = "[SYSTIME_ERROR] %32s() %05d: register callbck to jcs failed.\r\n";
    uVar2 = 0x91;
  }
  printf(__format,"systime_init",uVar2);
LAB_006665f0:
  if (systime_register_list != 0) {
    FUN_00407df0();
    systime_register_list = 0;
  }
  return 0xffffffff;
}

