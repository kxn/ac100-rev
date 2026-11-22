// func free_ac_cloud_mngt_hash @ 0048dd80 size=92

void free_ac_cloud_mngt_hash(int *param_1,int param_2)

{
  code *pcVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_2 == 1) {
      pcVar1 = free_client_hash_node;
    }
    else {
      pcVar1 = free_client_hash_node_no_json;
    }
    FUN_00408570(*param_1,pcVar1,0);
    FUN_00408310(*param_1);
    *param_1 = 0;
  }
  return;
}

