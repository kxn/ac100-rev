// func _tdcp_send_jcs_set @ 0050bf3c size=120

void _tdcp_send_jcs_set(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = json_object_object_get(param_1,"tdcp_msg");
  uVar1 = json_object_to_json_string_ext(uVar1,0);
  if (tdcp_debug_switch != 0) {
    printf("[TDCP_DEBUG]%s()/%d get tdcp_msg :%s\n","_tdcp_send_jcs_set",0x729,uVar1);
  }
  tdcp_send_request_to_ap_all(0,&DAT_00688af8,uVar1,0);
  return;
}

