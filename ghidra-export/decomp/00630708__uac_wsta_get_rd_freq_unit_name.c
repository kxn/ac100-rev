// func _uac_wsta_get_rd_freq_unit_name @ 00630708 size=60

char * _uac_wsta_get_rd_freq_unit_name(void)

{
  undefined4 uVar1;
  char *pcVar2;
  
  uVar1 = rdmngr_db_generate_rd_id();
  uVar1 = rdmngr_db_get_rd_freq_band(uVar1);
  pcVar2 = (char *)apdb_get_radio_freq_name_by_freq(uVar1);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = "---";
  }
  return pcVar2;
}

