// func _calculate_region_list_length @ 005baa38 size=184

int _calculate_region_list_length(byte *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*param_1 == 0) {
    iVar3 = 0;
    if ((capwap_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_WARNING]%32s():%4d region count is %d\n","_calculate_region_list_length",0x7a,
             (uint)*param_1);
    }
  }
  else {
    iVar3 = 0;
    for (iVar1 = 0; iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
      uVar2 = (uint)*(byte *)(*(int *)(param_1 + 4) + iVar3 + 1);
      iVar3 = iVar3 + uVar2 + *(byte *)(*(int *)(param_1 + 4) + iVar3 + uVar2 + 2) + 3;
    }
  }
  return iVar3;
}

