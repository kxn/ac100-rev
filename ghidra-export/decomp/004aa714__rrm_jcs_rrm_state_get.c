// func _rrm_jcs_rrm_state_get @ 004aa714 size=140

void _rrm_jcs_rrm_state_get(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = rrm_db_state_get();
    uVar1 = json_object_new_int(uVar1);
    json_object_object_add(param_2,"state",uVar1);
    return;
  }
  if (rrm_err_switch != '\0') {
    printf("[RRM_ERROR]%s()/%d inputs error.\n","_rrm_jcs_rrm_state_get",0x93a);
    return;
  }
  return;
}

