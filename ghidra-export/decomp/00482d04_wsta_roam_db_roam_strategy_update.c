// func wsta_roam_db_roam_strategy_update @ 00482d04 size=188

void wsta_roam_db_roam_strategy_update(uint *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  code *pcVar5;
  
  puVar3 = &wsta_roam_strategy_fun;
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  iVar1 = l_wsta_roam_strategy;
  iVar2 = 2;
  for (iVar4 = 0; iVar4 < strategy_reg_num; iVar4 = iVar4 + 1) {
    pcVar5 = (code *)*puVar3;
    puVar3 = puVar3 + 1;
    iVar2 = (*pcVar5)(iVar2);
  }
  l_wsta_roam_strategy = iVar2;
  if (param_1 != (uint *)0x0) {
    *param_1 = (uint)(iVar1 != iVar2);
  }
  FUN_00407f30(l_wsta_roam_data);
  return;
}

