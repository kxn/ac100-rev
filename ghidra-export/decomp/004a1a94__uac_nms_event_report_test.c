// func _uac_nms_event_report_test @ 004a1a94 size=40

undefined4 _uac_nms_event_report_test(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  undefined1 auStack_2e0 [16];
  undefined2 local_2d0;
  
  local_2d0 = param_3;
  _uac_nms_event_report_request(param_1,param_2,auStack_2e0,0);
  return 0;
}

