// func get_upstream_load_by_mac @ 0066c650 size=1

undefined8 get_upstream_load_by_mac(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  FUN_004082d0(l_stats_data,0xffffffff);
  iVar1 = FUN_00407fa0(DAT_007cc8e0,param_1);
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x34);
    uVar2 = *(undefined4 *)(iVar1 + 0x30);
  }
  FUN_00407f30(l_stats_data);
  return CONCAT44(uVar2,uVar3);
}

