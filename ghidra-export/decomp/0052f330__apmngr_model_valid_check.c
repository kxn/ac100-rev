// func _apmngr_model_valid_check @ 0052f330 size=588

undefined4 _apmngr_model_valid_check(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_2e8 [124];
  int local_26c;
  undefined1 auStack_180 [124];
  int local_104;
  int local_100;
  
  memset(auStack_180,0,0x168);
  memset(auStack_2e8,0,0x168);
  memset(auStack_180,0,0x168);
  memset(auStack_2e8,0,0x168);
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar6 = 1;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input params invalid.\n","_apmngr_model_valid_check",0xc76);
    }
  }
  else {
    iVar1 = param_2[1];
    iVar2 = apdb_get_ap_update_type
                      (*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,param_2[2],param_2[3],
                       *param_2,iVar1,auStack_180,auStack_2e8);
    if ((apmngr_debug_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      if (*(int *)(param_1 + 0xc) == 0) {
        pcVar4 = "Template";
      }
      else {
        pcVar4 = "AP";
      }
      iVar1 = iVar2;
      printf("[APMNGR_DEBUG]%s()/%d %s(%d)\'s model change type is %d.\n",
             "_apmngr_model_valid_check",0xc7d,pcVar4,(uint)*(ushort *)(param_1 + 0x10),iVar2);
    }
    if (iVar2 == 1) {
      if (apmngr_debug_switch == '\0') {
        iVar1 = *(int *)(param_1 + 0xc);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar1 = *(int *)(param_1 + 0xc);
        }
        else {
          printf("[APMNGR_DEBUG]%s()/%d AP(id: %d, name: %s) will be deleted because defination in new AP database changed.\n"
                 ,"_apmngr_model_valid_check",0xc81,(uint)*(ushort *)(param_1 + 0x10),param_1 + 0x4e
                 ,iVar1);
          iVar1 = *(int *)(param_1 + 0xc);
        }
      }
      if (iVar1 == 0) {
        apmngr_template_delete(param_1 + 0x10,1,0);
        uVar6 = 0;
      }
      else {
        apmngr_ap_delete(param_1 + 0x10,1,1,0x3cf4,0);
        uVar6 = 0;
      }
    }
    else {
      uVar5 = 0;
      uVar6 = uVar5;
      if ((((iVar2 == 2) && (local_26c != local_104)) && (local_104 != 0)) &&
         ((uVar6 = 0, local_100 == 0 && (uVar6 = 0, *(int *)(param_1 + 0x14) == 0)))) {
        apmngr_ap_role_update(*(undefined2 *)(param_1 + 0x10),1,0xffff);
        uVar6 = uVar5;
      }
    }
  }
  return uVar6;
}

