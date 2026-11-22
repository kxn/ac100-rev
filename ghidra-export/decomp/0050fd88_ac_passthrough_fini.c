// func ac_passthrough_fini @ 0050fd88 size=28

void ac_passthrough_fini(void)

{
  ac_passthrough_reponse_fini();
  tdcp_fini();
  return;
}

