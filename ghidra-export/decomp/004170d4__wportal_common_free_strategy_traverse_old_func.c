// func _wportal_common_free_strategy_traverse_old_func @ 004170d4 size=328

undefined4 _wportal_common_free_strategy_traverse_old_func(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    if (*(int *)(param_1 + 4) < g_max_free_strategy) {
      uVar3 = 0;
      puVar2 = *(undefined4 **)(param_1 + 8);
      if (*(char *)(param_2 + 0xa0) == '\0') {
        *puVar2 = *(undefined4 *)(param_2 + 0x9c);
        puVar2[1] = *(undefined4 *)(param_2 + 0xa4);
        puVar2[2] = *(undefined4 *)(param_2 + 0xa8);
        puVar2[3] = *(undefined4 *)(param_2 + 0xac);
        memcpy(puVar2 + 4,(void *)(param_2 + 0xb0),6);
        puVar2[6] = *(undefined4 *)(param_2 + 0xb8);
        puVar2[7] = *(undefined4 *)(param_2 + 0xbc);
        puVar2[8] = *(undefined4 *)(param_2 + 0xc0);
        puVar2[9] = *(undefined4 *)(param_2 + 0xc4);
        puVar2[10] = *(undefined4 *)(param_2 + 200);
        puVar2[0xb] = *(undefined4 *)(param_2 + 0xcc);
        puVar2[0xc] = *(undefined4 *)(param_2 + 0xd0);
        if (g_portal_auth_mode == 0) {
          puVar2[3] = 0;
        }
        uVar3 = 0;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x34;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      }
    }
    else if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Free strategy exceed count MAX: %d\n",
             "_wportal_common_free_strategy_traverse_old_func",0x17f4,g_max_free_strategy);
    }
  }
  return uVar3;
}

