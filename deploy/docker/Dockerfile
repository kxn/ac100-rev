ARG GO_IMAGE=golang:1.26-alpine
ARG RUNTIME_IMAGE=alpine:3.24
FROM --platform=$BUILDPLATFORM ${GO_IMAGE} AS build
WORKDIR /src
COPY uacgo/go.mod uacgo/go.sum ./
RUN --mount=type=cache,target=/go/pkg/mod go mod download
COPY uacgo/ ./
ARG TARGETOS
ARG TARGETARCH
RUN --mount=type=cache,target=/go/pkg/mod --mount=type=cache,target=/root/.cache/go-build \
    CGO_ENABLED=0 GOOS=$TARGETOS GOARCH=$TARGETARCH go build -trimpath -buildvcs=false -ldflags='-s -w' -o /out/acd ./cmd/acd && \
    mkdir -p /out/seed/data && cp data/identity.json data/apdb.json /out/seed/data/

FROM ${RUNTIME_IMAGE} AS runtime
ARG VCS_REF=unknown
LABEL org.opencontainers.image.title="Go AC" \
      org.opencontainers.image.revision=$VCS_REF
COPY --from=build /out/acd /usr/local/bin/acd
COPY --chmod=0755 deploy/docker/entrypoint.sh /usr/local/bin/go-ac-entrypoint
COPY uacgo/data/identity.json uacgo/data/apdb.json /usr/share/go-ac/defaults/
ENV GOMEMLIMIT=64MiB \
    AC_DATA_DIR=/data \
    AC_INTERFACE=eth0 \
    AC_CONTROL_PORT=5246 \
    AC_HTTP_HOST=0.0.0.0 \
    AC_HTTP_PORT=8090 \
    AC_DTLS_CERT=/certs/cacert.pem \
    AC_DTLS_KEY=/certs/privkey.pem \
    AC_DHCP_CONFIG=/etc/go-ac/ap-dhcp.json
EXPOSE 5246/udp 8090/tcp
ENTRYPOINT ["/usr/local/bin/go-ac-entrypoint"]

FROM runtime AS dhcp
COPY --from=build --chown=0:0 /out/seed/ /
WORKDIR /data
ENV AC_DHCP_ENABLED=1
USER 0:0
EXPOSE 67/udp

FROM runtime AS no-dhcp
COPY --from=build --chown=10001:10001 /out/seed/ /
WORKDIR /data
ENV AC_DHCP_ENABLED=0
USER 10001:10001
