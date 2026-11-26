#!/usr/bin/env bash
# Build Linux images locally, then save single-platform Docker archives for RouterOS.
set -euo pipefail
repo_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
platforms=linux/arm64
variant=all
image_name=go-ac
image_tag=latest
output_dir="$repo_root/dist/docker"
export_images=1
usage() {
    cat <<'HELP'
Usage: tools/build_docker.sh [options]
  --platform linux/arm64[,linux/amd64]  Default: linux/arm64
  --variant all|no-dhcp|dhcp           Default: all
  --name IMAGE                        Default: go-ac
  --tag TAG                           Default: latest
  --output-dir DIR                    Default: dist/docker
  --load-only                         Build/load without saving .tar archives
  --help
Tags: IMAGE:TAG-arm64 and IMAGE:TAG-arm64-dhcp (likewise amd64).
Requires Docker with Buildx. Uses native Go cross-compilation; no target RUN/QEMU.
Does not publish images or run containers. GO_IMAGE and RUNTIME_IMAGE override bases.
HELP
}
while (($#)); do
    case "$1" in
        --help|-h) usage; exit 0 ;;
        --platform|--variant|--name|--tag|--output-dir)
            if (($# < 2)); then echo "Missing value for $1" >&2; exit 2; fi
            case "$1" in
                --platform) platforms=$2 ;;
                --variant) variant=$2 ;;
                --name) image_name=$2 ;;
                --tag) image_tag=$2 ;;
                --output-dir) output_dir=$2 ;;
            esac
            shift 2 ;;
        --load-only) export_images=0; shift ;;
        *) echo "Unknown option: $1" >&2; usage >&2; exit 2 ;;
    esac
done
case "$variant" in all) variants=(no-dhcp dhcp) ;; no-dhcp|dhcp) variants=("$variant") ;; *) echo "Invalid variant: $variant" >&2; exit 2 ;; esac
IFS=, read -r -a targets <<< "$platforms"
for platform in "${targets[@]}"; do
    case "$platform" in linux/amd64|linux/arm64) ;; *) echo "Unsupported platform: $platform" >&2; exit 2 ;; esac
done
docker buildx version >/dev/null
revision=$(git -C "$repo_root" rev-parse HEAD)
if ((export_images)); then mkdir -p -- "$output_dir"; fi
for platform in "${targets[@]}"; do
    arch=${platform#linux/}
    for flavor in "${variants[@]}"; do
        tag="$image_name:$image_tag-$arch"
        if [[ $flavor == dhcp ]]; then tag+=-dhcp; fi
        docker buildx build --platform "$platform" --target "$flavor" \
            --file "$repo_root/deploy/docker/Dockerfile" --tag "$tag" --load \
            --provenance=false --sbom=false \
            --build-arg "VCS_REF=$revision" \
            --build-arg "GO_IMAGE=${GO_IMAGE:-golang:1.26-alpine}" \
            --build-arg "RUNTIME_IMAGE=${RUNTIME_IMAGE:-alpine:3.24}" "$repo_root"
        if ((export_images)); then
            archive="$output_dir/go-ac-$image_tag-$arch"
            if [[ $flavor == dhcp ]]; then archive+=-dhcp; fi
            archive+=.tar
            docker image save --output "$archive" "$tag"
            (cd -- "$output_dir" && sha256sum -- "$(basename -- "$archive")" > "$(basename -- "$archive").sha256")
            echo "Saved $tag to $archive"
        fi
    done
done
