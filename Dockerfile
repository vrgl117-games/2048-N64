FROM vieux/libdragon:conker64

RUN apt-get update && apt-get install -yq git libsox-fmt-all sox

WORKDIR /2048-N64