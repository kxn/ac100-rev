// func rdmngr_db_init_state @ 00619dd0 size=356

undefined4 rdmngr_db_init_state(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  char cVar6;
  
  iVar4 = DAT_007cc65c;
  if ((int)param_1 < 0) {
LAB_00619e20:
    if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Invalid rd_idx:%d\n","rdmngr_db_init_state",0x541,param_1);
    }
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  iVar3 = apmngr_db_get_sensor_max();
  if (((uint)((iVar1 + iVar2 + iVar3) * iVar4) <= param_1) ||
     (iVar4 = *(int *)(DAT_007cc650 + param_1 * 8 + 4), iVar4 == 0)) goto LAB_00619e20;
  if (*(char *)(iVar4 + 0x48) == '\x01') {
    uVar5 = 3;
  }
  else {
    if (*(char *)(iVar4 + 0x48) != '\0') {
      cVar6 = *(char *)(iVar4 + 0x41);
      goto LAB_00619e94;
    }
    uVar5 = 4;
  }
  *(undefined1 *)(iVar4 + 0x4e) = uVar5;
  cVar6 = *(char *)(iVar4 + 0x41);
LAB_00619e94:
  uVar5 = 3;
  if (cVar6 != '\x01') {
    uVar5 = 4;
  }
  *(undefined1 *)(iVar4 + 0x4f) = uVar5;
  uVar5 = 3;
  if (*(char *)(iVar4 + 0x42) != '\x01') {
    uVar5 = 4;
  }
  *(undefined1 *)(iVar4 + 0x50) = uVar5;
  *(undefined1 *)(iVar4 + 0x3a) = 0xff;
  *(undefined2 *)(iVar4 + 0x3c) = 0xffff;
  *(undefined1 *)(iVar4 + 0x40) = 0xff;
  if (rdmngr_debug_switch == 0) {
    return 0;
  }
  iVar4 = is_target_debug_ap();
  if (iVar4 == 0) {
    return 0;
  }
  printf("[RDMNGR_DEBUG]%s()/%d rdmngr_init_state() OK.\n","rdmngr_db_init_state",0x566);
  return 0;
}

