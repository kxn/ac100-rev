// func _apupd_remove_group_in_model_entry @ 0064c088 size=184

void _apupd_remove_group_in_model_entry(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = 0;
  if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
    iVar6 = param_2[1];
    puVar2 = (ushort *)*param_2;
    for (; iVar3 < iVar6; iVar3 = iVar3 + 1) {
      if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
        if ((*puVar2 < 0x200) &&
           (uVar5 = *puVar2 + 1,
           (*(uint *)(param_1 + (((int)uVar5 >> 5) + 6) * 4) >> (uVar5 & 0x1f) & 1) != 0)) {
          uVar1 = *puVar2;
          goto LAB_0064c0fc;
        }
      }
      else {
        uVar1 = *puVar2;
LAB_0064c0fc:
        if (uVar1 < 0x200) {
          uVar5 = uVar1 + 1;
          puVar4 = (uint *)(param_1 + (((int)uVar5 >> 5) + 6) * 4);
          *puVar4 = ~(1 << (uVar5 & 0x1f)) & *puVar4;
        }
      }
      puVar2 = puVar2 + 1;
    }
  }
  return;
}

