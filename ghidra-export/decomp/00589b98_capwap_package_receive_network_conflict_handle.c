// func capwap_package_receive_network_conflict_handle @ 00589b98 size=152

undefined4 capwap_package_receive_network_conflict_handle(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (((param_1 != 0) && (ac != 0)) && (iVar1 = FUN_004081b0(ac + 0xcc24), iVar1 != 0)) {
    for (iVar1 = FUN_004081b0(ac + 0xcc24); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      (**(code **)(iVar1 + 0xc))(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

