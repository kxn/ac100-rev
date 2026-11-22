// func cloud_mngt_send_to_cloud_thread_callback @ 0048c948 size=1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cloud_mngt_send_to_cloud_thread_callback(void)

{
  int iVar1;
  undefined1 auStack_98 [136];
  
  memcpy(auStack_98,
         "aaaaaabbbbb bccccccccccccccccccccccdddddddddddddddddddddddddfffffffffffffffffffffffffeeeeeeeeeeeeeeeeeeeeeeeeeeeddddddddddddddddd"
         ,0x82);
  for (iVar1 = 0; iVar1 < _test_report_num; iVar1 = iVar1 + 1) {
    cloud_mngt_send_to_cloud(3,auStack_98);
  }
  return;
}

