// func _wserv_db_set_ap_id_bm_by_rd @ 005e904c size=152

void _wserv_db_set_ap_id_bm_by_rd(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  
  uVar1 = rdmngr_db_generate_ap_id(*param_1);
  iVar5 = *param_2;
  piVar4 = (int *)param_2[1];
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    if ((int)uVar1 < iVar2) {
      puVar6 = (uint *)(iVar5 + ((int)uVar1 >> 5) * 4);
      uVar3 = *puVar6;
      if ((((int)uVar3 >> (uVar1 & 0x1f) & 1U) == 0) &&
         (*puVar6 = uVar3 | 1 << (uVar1 & 0x1f), piVar4 != (int *)0x0)) {
        *piVar4 = *piVar4 + 1;
      }
    }
  }
  return;
}

