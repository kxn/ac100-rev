// func _rdmngr_db_priv_ap_rate_set @ 00409638 size=44

void _rdmngr_db_priv_ap_rate_set(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    uVar2 = *param_2;
    param_2 = param_2 + 1;
    *(char *)(param_1 + iVar1) = (char)uVar2;
  }
  return;
}

