// func rdmngr_db_rd_update @ 00620834 size=536

undefined4 rdmngr_db_rd_update(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *__dest;
  char *__format;
  void *__src;
  undefined4 uVar6;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar5 = DAT_007cc65c;
  if ((int)uVar1 < 0) {
LAB_00620898:
    if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d rd_id[%d] is invalid!\n","rdmngr_db_rd_update",0xd41,param_1);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar2 = apmngr_db_get_ap_max();
  iVar3 = apmngr_db_get_template_max();
  iVar4 = apmngr_db_get_sensor_max();
  if ((uint)((iVar2 + iVar3 + iVar4) * iVar5) <= uVar1) goto LAB_00620898;
  __dest = (int *)FUN_00408450(0x54,0xd44);
  if (__dest == (int *)0x0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 != 0) {
      printf("[RDMNGR_ERROR]%s()/%d no momery.\n","rdmngr_db_rd_update",0xd47);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  FUN_004082d0(DAT_007cc64c,0xffffffff);
  __src = *(void **)(DAT_007cc650 + uVar1 * 8 + 4);
  if (__src == (void *)0x0) {
    if ((rdmngr_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_0062096c;
    __format = "[RDMNGR_ERROR]%s()/%d rd_id[%d] is invalid!\n";
    uVar6 = 0xd4e;
  }
  else {
    memcpy(__dest,__src,0x54);
    if (*__dest != -1) {
      rdmngr_db_msg_send(param_2,__dest);
      FUN_00407f30(DAT_007cc64c);
      return 0;
    }
    if ((rdmngr_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_0062096c;
    __format = "[RDMNGR_ERROR]%s()/%d rd entry[%d] update error.\n";
    uVar6 = 0xd59;
  }
  printf(__format,"rdmngr_db_rd_update",uVar6,param_1);
LAB_0062096c:
  FUN_00407f30(DAT_007cc64c);
  FUN_00407df0(__dest);
  return 0xffffffff;
}

