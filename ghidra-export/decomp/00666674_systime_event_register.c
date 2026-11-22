// func systime_event_register @ 00666674 size=380

undefined4 systime_event_register(void *param_1)

{
  void *__s;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  if ((param_1 == (void *)0x0) || (*(int *)((int)param_1 + 0x84) == 0)) {
    if (g_systime_error == 0) {
      return 0xffffffff;
    }
    __format = "[SYSTIME_ERROR] %32s() %05d: inputs error.\r\n";
    uVar2 = 0xb2;
  }
  else {
    __s = (void *)FUN_00408450(0x98,0xb6);
    if (__s != (void *)0x0) {
      memset(__s,0,0x98);
      iVar1 = FUN_004081b0(systime_register_list);
      if (iVar1 == 0) {
LAB_00666704:
        FUN_004086b0(systime_register_list,__s);
      }
      else {
        iVar3 = *(int *)(iVar1 + 0x8c);
        while (*(int *)((int)param_1 + 0x80) <= iVar3) {
          iVar1 = FUN_00408680();
          if (iVar1 == 0) goto LAB_00666704;
          iVar3 = *(int *)(iVar1 + 0x8c);
        }
        FUN_00408170(iVar1,__s);
      }
      memcpy((void *)((int)__s + 0xc),param_1,0x8c);
      if (g_systime_debug == 0) {
        return 0;
      }
      uVar4 = *(undefined4 *)((int)param_1 + 0x80);
      uVar2 = FUN_00407fe0(systime_register_list);
      printf("[SYSTIME_DEBUG] %32s() %05d: systime register: name[%s] priority[%d]. list size=%d.\r\n"
             ,"systime_event_register",0xcf,param_1,uVar4,uVar2);
      return 0;
    }
    if (g_systime_error == 0) {
      return 0xffffffff;
    }
    __format = "[SYSTIME_ERROR] %32s() %05d: no memory.\r\n";
    uVar2 = 0xb8;
  }
  printf(__format,"systime_event_register",uVar2);
  return 0xffffffff;
}

