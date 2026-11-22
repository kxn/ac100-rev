// func serv_msg_mngr_init @ 00599a10 size=376

undefined4 serv_msg_mngr_init(void)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = &g_serv_msg_mngr;
  iVar4 = 1;
  do {
    if (*piVar3 == 0) {
      iVar1 = FUN_00408450(0x10,0x26b);
      *piVar3 = iVar1;
      if (iVar1 == 0) {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_00599a9c;
        uVar2 = 0x26e;
        goto LAB_00599b78;
      }
      __s = (void *)*piVar3;
    }
    else {
      __s = (void *)*piVar3;
    }
    memset(__s,0,0x10);
    *(int *)*piVar3 = iVar4;
    iVar4 = iVar4 + 1;
    iVar1 = *piVar3;
    piVar3 = piVar3 + 1;
    FUN_0051ad88(iVar1 + 4);
  } while (iVar4 != 0x1b);
  iVar4 = 0x33dd01;
  piVar3 = &g_serv_ie_msg_mngr;
  do {
    if (*piVar3 == 0) {
      iVar1 = FUN_00408450(0x10,0x27c);
      *piVar3 = iVar1;
      if (iVar1 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          uVar2 = 0x27f;
LAB_00599b78:
          printf("[CW_ERROR]%32s():%4d memory malloc failed\n","serv_msg_mngr_init",uVar2);
        }
LAB_00599a9c:
        serv_msg_mngr_destroy();
        return 0xffffffff;
      }
    }
    memset((void *)*piVar3,0,0x10);
    *(int *)*piVar3 = iVar4;
    iVar4 = iVar4 + 1;
    iVar1 = *piVar3;
    piVar3 = piVar3 + 1;
    FUN_0051ad88(iVar1 + 4);
    if (iVar4 == 0x33dd03) {
      return 0;
    }
  } while( true );
}

