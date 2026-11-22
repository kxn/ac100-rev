// func rdmngr_db_ap_firm @ 00620fd4 size=560

undefined4 rdmngr_db_ap_firm(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int *__dest;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 1;
  __dest = (int *)0x0;
  FUN_004082d0(DAT_007cc64c,0xffffffff);
  while( true ) {
    if (param_2 < (int)uVar3) {
      FUN_00407f30(DAT_007cc64c);
      return 0;
    }
    iVar1 = rdmngr_db_generate_rd_idx(param_1,uVar3);
    uVar4 = uVar3 & 0xf | param_1 << 4;
    if (*(int *)(DAT_007cc650 + iVar1 * 8 + 4) == 0) break;
    __dest = (int *)FUN_00408450(0x54,0xc62);
    if (__dest == (int *)0x0) {
      if (rdmngr_err_switch == 0) {
        uVar3 = uVar3 + 1;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          uVar3 = uVar3 + 1;
        }
        else {
          printf("[RDMNGR_ERROR]%s()/%d no momery.\n","rdmngr_db_ap_firm",0xc65);
          uVar3 = uVar3 + 1;
        }
      }
    }
    else {
      iVar1 = DAT_007cc650 + iVar1 * 8;
      memcpy(__dest,*(void **)(iVar1 + 4),0x54);
      if (*__dest == -1) {
        if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
        goto LAB_00621174;
        __format = "[RDMNGR_ERROR]%s()/%d rd entry[%d] init error.\n";
        uVar2 = 0xc73;
        goto LAB_006211f4;
      }
      *(undefined1 *)((int)__dest + 0x4d) = 1;
      *(undefined1 *)(*(int *)(iVar1 + 4) + 0x4d) = 1;
      rdmngr_db_msg_send(0,__dest);
      rdmngr_callback_proc(7,uVar4,0,0);
      uVar3 = uVar3 + 1;
    }
  }
  if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00621174;
  __format = "[RDMNGR_ERROR]%s()/%d rd entry[%d] get error.\n";
  uVar2 = 0xc5f;
LAB_006211f4:
  printf(__format,"rdmngr_db_ap_firm",uVar2,uVar4);
LAB_00621174:
  FUN_00407f30(DAT_007cc64c);
  if (__dest == (int *)0x0) {
    return 0xffffffff;
  }
  FUN_00407df0(__dest);
  return 0xffffffff;
}

