// func cw_ac_manager_event_add @ 0058ae74 size=268

undefined4 cw_ac_manager_event_add(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_2 == 0) {
    uVar2 = 0x495;
    pcVar3 = "data";
  }
  else if (ac == 0) {
    uVar2 = 0x496;
    pcVar3 = "ac";
  }
  else {
    if (param_1 < *(uint *)(ac + 0x18)) {
      iVar1 = cw_packet_queue_push_tail
                        (*(undefined4 *)(*(int *)(ac + 0x1c) + param_1 * 0xa0 + 0x38));
      if (iVar1 != -1) {
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d insert manager event data to manager_queue failed.\n",
             "cw_ac_manager_event_add",0x49a);
      return 0xffffffff;
    }
    uVar2 = 0x497;
    pcVar3 = "data_index < ac->ac_data_size";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_manager_event_add",uVar2,pcVar3);
  return 0xffffffff;
}

