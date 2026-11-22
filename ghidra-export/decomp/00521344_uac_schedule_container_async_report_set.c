// func uac_schedule_container_async_report_set @ 00521344 size=24

undefined4 uac_schedule_container_async_report_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x7c) = param_2;
  }
  return uVar1;
}

