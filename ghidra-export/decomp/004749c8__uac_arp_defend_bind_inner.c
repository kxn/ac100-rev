// func _uac_arp_defend_bind_inner @ 004749c8 size=164

int _uac_arp_defend_bind_inner
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar1 = arp_defend_db_batch_unbind(param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = arp_defend_db_batch_bind_no_optimize(param_2,param_3);
  }
  if (iVar1 != 0) {
    iVar1 = -1;
  }
  iVar2 = FUN_00474804(param_2,param_3,param_6);
  iVar3 = -1;
  if (iVar2 == 0) {
    iVar3 = iVar1;
  }
  return iVar3;
}

