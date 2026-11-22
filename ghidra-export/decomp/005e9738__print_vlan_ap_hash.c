// func _print_vlan_ap_hash @ 005e9738 size=1

void _print_vlan_ap_hash(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  printf("\nap[%d], record_cnt=%d\n",*param_1,(uint)*(byte *)(param_1 + 1));
  for (uVar3 = 0; uVar1 = rdmngr_profile_get_max_rd_per_ap(), uVar3 < uVar1; uVar3 = uVar3 + 1) {
    printf("  -> rd[%d] @ wlans[",uVar3);
    for (uVar1 = 0; uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar1 < uVar2; uVar1 = uVar1 + 1)
    {
      printf("%u/",(uint)*(byte *)(param_1[2] + uVar1));
    }
    puts("]");
    param_1 = param_1 + 1;
  }
  return;
}

