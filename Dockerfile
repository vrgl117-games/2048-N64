FROM anacierdem/libdragon

RUN apt-get update && apt-get install -yq libsox-fmt-all sox

WORKDIR /2048-N64