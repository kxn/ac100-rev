// func get_downstream_load_by_mac @ 0066c6d0 size=128

undefined8 get_downstream_load_by_mac(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  FUN_004082d0(l_stats_data,0xffffffff);
  iVar1 = FUN_00407fa0(DAT_007cc8e0,param_1);
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x3c);
    uVar2 = *(undefined4 *)(iVar1 + 0x38);
  }
  FUN_00407f30(l_stats_data);
  return CONCAT44(uVar2,uVar3);
}

