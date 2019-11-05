FROM anacierdem/libdragon

RUN apt-get update && apt-get install -yq lame

WORKDIR /game
