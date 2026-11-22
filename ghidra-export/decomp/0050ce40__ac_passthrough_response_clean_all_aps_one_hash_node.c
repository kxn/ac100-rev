// func _ac_passthrough_response_clean_all_aps_one_hash_node @ 0050ce40 size=144

void _ac_passthrough_response_clean_all_aps_one_hash_node(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    if (*param_2 == -1) {
      free_reponse_from_list();
      *param_1 = 0;
    }
    else {
      iVar1 = get_reponse_by_id_from_list();
      if (iVar1 != 0) {
        FUN_00408500(iVar1);
        if (*(int *)(iVar1 + 0x18) != 0) {
          FUN_00407df0();
          *(undefined4 *)(iVar1 + 0x18) = 0;
        }
        FUN_00407df0(iVar1);
        *param_1 = *param_1 + -1;
      }
    }
  }
  return;
}

