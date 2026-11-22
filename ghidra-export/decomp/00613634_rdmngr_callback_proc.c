// func rdmngr_callback_proc @ 00613634 size=396

undefined4
rdmngr_callback_proc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  iVar1 = FUN_004081b0(&g_rdmngr_cb_list);
  iVar3 = 0;
  do {
    if (iVar1 == 0) {
      return 0;
    }
    switch(param_1) {
    case 0:
      pcVar4 = *(code **)(iVar1 + 0x14);
      break;
    case 1:
      pcVar4 = *(code **)(iVar1 + 0x10);
      break;
    case 2:
      pcVar4 = *(code **)(iVar1 + 0x1c);
      goto LAB_0061373c;
    case 3:
      pcVar4 = *(code **)(iVar1 + 0x18);
      break;
    case 4:
      pcVar4 = *(code **)(iVar1 + 0x20);
      goto LAB_0061373c;
    case 5:
      pcVar4 = *(code **)(iVar1 + 0x24);
LAB_0061373c:
      if (pcVar4 != (code *)0x0) {
        iVar3 = (*pcVar4)(param_2,param_3,param_4);
      }
      goto switchD_006136b8_default;
    case 6:
      pcVar4 = *(code **)(iVar1 + 0x28);
      break;
    case 7:
      pcVar4 = *(code **)(iVar1 + 0x2c);
      break;
    case 8:
      pcVar4 = *(code **)(iVar1 + 0x30);
      break;
    default:
      goto switchD_006136b8_default;
    }
    if (pcVar4 != (code *)0x0) {
      iVar3 = (*pcVar4)(param_2);
    }
switchD_006136b8_default:
    if (((iVar3 != 0) && (rdmngr_err_switch != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Failed to proc %s callback of [%s].\n","rdmngr_callback_proc",
             0xa13,(&rdmngr_evt_str)[param_1],*(undefined4 *)(iVar1 + 0xc));
    }
    iVar1 = FUN_00408680(iVar1);
  } while( true );
}

