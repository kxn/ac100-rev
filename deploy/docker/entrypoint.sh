#!/bin/sh
set -eu
umask 077

: "${AC_DATA_DIR:=/data}"
: "${AC_INTERFACE:=eth0}"
: "${AC_CONTROL_PORT:=5246}"
: "${AC_HTTP_HOST:=0.0.0.0}"
: "${AC_HTTP_PORT:=8090}"
: "${AC_DTLS_CERT:=/certs/cacert.pem}"
: "${AC_DTLS_KEY:=/certs/privkey.pem}"
: "${AC_DHCP_CONFIG:=/etc/go-ac/ap-dhcp.json}"
: "${AC_DHCP_ENABLED:=0}"

# Explicit, one-time setup only; normal starts never alter certificate modes.
if [ "${1:-}" = init-certs ]; then
    for file in "$AC_DTLS_CERT" "$AC_DTLS_KEY"; do
        directory=$(dirname "$file")
        chown 0:10001 "$directory" "$file"
        chmod 750 "$directory"
        chmod 440 "$file"
    done
    echo "Certificate directory prepared for root or GID 10001; remount read-only."
    exit 0
fi

mkdir -p "$AC_DATA_DIR"
for name in identity.json apdb.json; do
    if [ ! -e "$AC_DATA_DIR/$name" ]; then
        cp "/usr/share/go-ac/defaults/$name" "$AC_DATA_DIR/$name"
    fi
done

# One-time preparation for empty RouterOS/bind mounts. This does not start AC.
if [ "${1:-}" = init-data ]; then
    owner=10001:10001
    if [ "$AC_DHCP_ENABLED" = 1 ]; then owner=0:0; fi
    chown -R "$owner" "$AC_DATA_DIR"
    chmod 700 "$AC_DATA_DIR"
    echo "Data initialized for UID/GID $owner."
    exit 0
fi

for file in "$AC_DTLS_CERT" "$AC_DTLS_KEY"; do
    if [ ! -r "$file" ]; then
        echo "Missing/unreadable AP DTLS certificate or key: $file (mount /certs read-only)." >&2
        exit 1
    fi
done

set -- /usr/local/bin/acd --data "$AC_DATA_DIR" --interface "$AC_INTERFACE" \
    --port "$AC_CONTROL_PORT" --http "$AC_HTTP_HOST:$AC_HTTP_PORT" --http-allow-remote \
    --dtls-cert "$AC_DTLS_CERT" --dtls-key "$AC_DTLS_KEY" "$@"
case "$AC_DHCP_ENABLED" in
    1) set -- "$@" --ap-dhcp "$AC_DHCP_CONFIG" ;;
    0) set -- "$@" --ap-dhcp off ;;
    *) echo "AC_DHCP_ENABLED must be 0 or 1" >&2; exit 1 ;;
esac
exec "$@"
