// func apmngr_callback_proc @ 0052a504 size=540

undefined4 apmngr_callback_proc(int param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  code *pcVar5;
  
  iVar1 = FUN_004081b0(&g_apmngr_callback_list);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    switch(param_1) {
    case 0:
      pcVar5 = *(code **)(iVar1 + 0x14);
      break;
    case 1:
      pcVar5 = *(code **)(iVar1 + 0x18);
      break;
    case 2:
      pcVar5 = *(code **)(iVar1 + 0x1c);
      break;
    case 3:
      pcVar5 = *(code **)(iVar1 + 0x20);
      break;
    case 4:
      pcVar5 = *(code **)(iVar1 + 0x2c);
      if (pcVar5 == (code *)0x0) goto switchD_0052a578_default;
      puVar3 = *(ushort **)param_2;
      puVar4 = *(ushort **)(param_2 + 2);
      goto LAB_0052a664;
    case 5:
      if (*(int *)(iVar1 + 0x34) == 0) goto switchD_0052a578_default;
      pcVar5 = *(code **)(iVar1 + 0x34);
      while (iVar2 = (*pcVar5)(param_2 + 4,MD5_Update,*(undefined4 *)param_2), iVar2 != 2) {
        if (iVar2 != 1) goto LAB_0052a594;
        pcVar5 = *(code **)(iVar1 + 0x34);
      }
      goto LAB_0052a59c;
    case 6:
      pcVar5 = *(code **)(iVar1 + 0x24);
      break;
    case 7:
      pcVar5 = *(code **)(iVar1 + 0x28);
      goto LAB_0052a658;
    case 8:
      if (*(code **)(iVar1 + 0x30) == (code *)0x0) goto switchD_0052a578_default;
      iVar2 = (**(code **)(iVar1 + 0x30))
                        (*(undefined4 *)param_2,*(undefined4 *)(param_2 + 2),
                         *(undefined4 *)(param_2 + 4));
      goto LAB_0052a594;
    case 9:
      pcVar5 = *(code **)(iVar1 + 0x38);
LAB_0052a658:
      puVar4 = param_2 + 4;
      if (pcVar5 == (code *)0x0) goto switchD_0052a578_default;
      puVar3 = (ushort *)(uint)*param_2;
LAB_0052a664:
      iVar2 = (*pcVar5)(puVar3,puVar4);
      goto LAB_0052a594;
    case 10:
      pcVar5 = *(code **)(iVar1 + 0x3c);
      if (pcVar5 != (code *)0x0) {
        puVar4 = param_2 + 0x16c;
        puVar3 = param_2;
        goto LAB_0052a664;
      }
      goto switchD_0052a578_default;
    case 0xb:
      pcVar5 = *(code **)(iVar1 + 0x40);
      break;
    case 0xc:
      pcVar5 = *(code **)(iVar1 + 0x44);
      break;
    case 0xd:
      pcVar5 = *(code **)(iVar1 + 0x48);
      break;
    default:
      goto switchD_0052a578_default;
    }
    if (pcVar5 != (code *)0x0) {
      iVar2 = (*pcVar5)(param_2);
LAB_0052a594:
      if (iVar2 != 0) {
LAB_0052a59c:
        if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APMNGR_ERROR]%s()/%d Failed to proc %s callback of [%s].\n",
                 "apmngr_callback_proc",0x1d0,(&apmngr_evt_str)[param_1],
                 *(undefined4 *)(iVar1 + 0xc));
        }
      }
    }
switchD_0052a578_default:
    iVar1 = FUN_00408680(iVar1);
  } while( true );
}

