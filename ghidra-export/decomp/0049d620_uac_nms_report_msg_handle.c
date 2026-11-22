// func uac_nms_report_msg_handle @ 0049d620 size=80

void uac_nms_report_msg_handle(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = json_tokener_parse(), iVar1 != 0)) {
    _ac_passthrough_jcs_set(iVar1,0);
    json_object_put(iVar1);
    return;
  }
  return;
}

