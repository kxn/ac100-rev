// func wsta_roam_db_global_stats_clear @ 004825f4 size=88

undefined4 wsta_roam_db_global_stats_clear(void)

{
  void *__s;
  
  __s = DAT_0076755c;
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  memset(__s,0,0x78);
  FUN_00407f30(l_wsta_roam_data);
  return 0;
}

