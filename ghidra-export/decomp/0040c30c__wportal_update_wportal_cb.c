// func _wportal_update_wportal_cb @ 0040c30c size=764

undefined4 _wportal_update_wportal_cb(undefined4 param_1,void *param_2)

{
  void *__s;
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  __s = (void *)FUN_00408450(0x14,0x2c7);
  if (__s == (void *)0x0) {
    if (wportal_err_switch == 0) {
      iVar2 = *(int *)((int)param_2 + 0xc);
      goto LAB_0040c498;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)((int)param_2 + 0xc);
      goto LAB_0040c498;
    }
    printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_wportal_cb",0x2ca);
    goto LAB_0040c494;
  }
  memset(__s,0,0x14);
  *(undefined4 *)((int)__s + 0xc) = 1;
  pvVar1 = (void *)FUN_00408450(0x14,0x2d0);
  *(void **)((int)__s + 0x10) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(__s), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_wportal_cb",0x2d3);
    }
    goto LAB_0040c48c;
  }
  memset(pvVar1,0,0x14);
  puVar3 = *(undefined4 **)((int)__s + 0x10);
  *puVar3 = param_1;
  memcpy(puVar3 + 1,param_2,0x10);
  puVar3[3] = 0;
  puVar3[4] = 0;
  if (*(int *)((int)param_2 + 8) == 0) {
LAB_0040c3d8:
    if (*(int *)((int)param_2 + 0xc) == 0) {
LAB_0040c434:
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d update rdt ftt list: WPORTAL_MSG_TYPE_UPDATE_RDT_CB\n",
               "_wportal_update_wportal_cb",0x300);
      }
      FUN_004082d0(wportal_update_rdt_ftt_mutex,0xffffffff);
      FUN_004086b0(&g_wportal_update_rdt_ftt_list,__s);
      FUN_004084b0(wportal_update_rdt_ftt_cond);
      FUN_00407f30(wportal_update_rdt_ftt_mutex);
      return 0;
    }
    pvVar1 = (void *)FUN_00408450(0x94,0x2f1);
    puVar3[4] = pvVar1;
    if (pvVar1 != (void *)0x0) {
      memset(pvVar1,0,0x94);
      memcpy((void *)puVar3[4],*(void **)((int)param_2 + 0xc),0x94);
      FUN_0051ad88(puVar3[4] + 0x88);
      FUN_004082c0(puVar3[4] + 0x88,*(int *)((int)param_2 + 0xc) + 0x88);
      goto LAB_0040c434;
    }
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_wportal_cb",0x2f4);
    }
    FUN_00407df0(puVar3[3]);
  }
  else {
    pvVar1 = (void *)FUN_00408450(0x84,0x2e3);
    puVar3[3] = pvVar1;
    if (pvVar1 != (void *)0x0) {
      memset(pvVar1,0,0x84);
      memcpy((void *)puVar3[3],*(void **)((int)param_2 + 8),0x84);
      goto LAB_0040c3d8;
    }
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_wportal_cb",0x2e6);
    }
  }
  FUN_00407df0(puVar3);
LAB_0040c48c:
  while( true ) {
    FUN_00407df0(__s);
LAB_0040c494:
    iVar2 = *(int *)((int)param_2 + 0xc);
LAB_0040c498:
    __s = (void *)FUN_004081b0(iVar2 + 0x88);
    if (__s == (void *)0x0) break;
    FUN_00408500(__s);
  }
  return 0xffffffff;
}

