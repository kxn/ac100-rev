// func get_report_ulr @ 004a04d0 size=40

undefined * get_report_ulr(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 < 3) {
    puVar1 = (&PTR_s__tums_devmsg_v1_reportDevEventMs_0069cc98)[param_1];
  }
  return puVar1;
}

