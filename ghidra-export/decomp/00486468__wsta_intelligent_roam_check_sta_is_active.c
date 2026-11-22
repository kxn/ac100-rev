// func _wsta_intelligent_roam_check_sta_is_active @ 00486468 size=224

undefined4 _wsta_intelligent_roam_check_sta_is_active(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_2e8 [728];
  
  uVar3 = 0xffffffff;
  memset(auStack_2e8,0,0x2d8);
  if ((param_1 != 0) && (uVar3 = 0xffffffff, param_2 != (int *)0x0)) {
    iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 8),auStack_2e8);
    if (iVar1 == -1) {
      if ((*(byte *)(param_1 + 0xc) & 8) == 0) {
        if (wsta_roam_debug_switch == '\0') {
          return 0xffffffff;
        }
        printf("[WSTA_ROAM_DEBUG]%s()/%d get ap entry by id failed.\n",
               "_wsta_intelligent_roam_check_sta_is_active",0xaeb);
        return 0xffffffff;
      }
      uVar2 = *(uint *)(param_1 + 0x24);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x24);
    }
    if ((1 < uVar2) || (uVar3 = 0, 1 < *(uint *)(param_1 + 0x28))) {
      uVar3 = 0;
      *param_2 = *param_2 + 1;
    }
  }
  return uVar3;
}

