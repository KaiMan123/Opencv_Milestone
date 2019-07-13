#!/bin/bash

language='Nothing'
selectChapter='Nothing'
com='Nothing'
image='--image ./Resources/test.jpg'
video='--video ./Resources/following.mp4'

while [ true ] 
do
    while [ $language == 'Nothing' ]
    do
        clear
        echo -e '\e[1;32m********** Choose Language **********\e[0m'
        echo -e '\e[1;32m0: c++\e[0m'
        echo -e '\e[1;32m1: python\e[0m'
        echo -e '\e[1;36mPlease choose one language:\e[0m'
        read -p $'\e[1;33m>>\e[0m ' com

        if [ $com ]; then
            com=$(tr '[A-Z]' '[a-z]' <<< $com)
        fi

        if [ $com == 'exit' ]; then
            exit 1
        fi

        if [ $com == 'python' ] || [ $com == '1' ]; then
            language='python'
        else if [ $com == 'c++' ] || [ $com == '0' ]; then
                language='c++'
            fi
        fi
    done

    while [ $selectChapter == 'Nothing' ]
    do
        chapters=$(ls ./$language)
        counter=0
        clear
        echo -e '\e[1;32m********** Choose  Chapter **********\e[0m'
        for c in $chapters
        do
            echo -e '\e[1;32m'$counter': ' $c'\e[0m'
            (( counter++ ))
        done

        echo -e '\e[1;36mPlease choose one chapter:\e[0m'
        echo -e '\e[1;35mInput (back/b) can go back to choose language.\e[0m'
        read -p $'\e[1;33m'$language$'>>\e[0m ' com

        if [ $com ]; then
            com=$(tr '[A-Z]' '[a-z]' <<< $com)
        fi

        if [ $com == 'exit' ]; then
            exit 1
        fi

        if [ $com == 'back' ] || [ $com == 'b' ]; then
            language='Nothing'
            break
        fi

        counter=0
        for c in $chapters
        do
            chapter=$(tr '[A-Z]' '[a-z]' <<< $c)
            if [ $com == $chapter ] || [ $com == $counter ]; then
                selectChapter=$c
            fi
            (( counter++ ))
        done
    done
    
    if [ $language != 'Nothing' ] && [ $selectChapter != 'Nothing' ]; then
        selectItem='Nothing'
        items=$(ls ./$language/$selectChapter | grep '.py\|.cpp')
        counter=0
        clear
        echo -e '\e[1;32m********** Choose     Item **********\e[0m'
        for i in $items
        do
            echo -e '\e[1;32m'$counter': ' $i'\e[0m'
            (( counter++ ))
        done

        echo -e '\e[1;36mPlease choose one item:\e[0m'
        echo -e '\e[1;35mInput (back/b) can go back to choose language.\e[0m'
        read -p $'\e[1;33m'$language'>>'$selectChapter$'>>\e[0m ' com

        if [ $com ]; then
            com=$(tr '[A-Z]' '[a-z]' <<< $com)
        fi

        if [ $com == 'exit' ]; then
            exit 1
        fi

        if [ $com == 'back' ] || [ $com == 'b' ]; then
            selectChapter='Nothing'
            continue
        fi

        counter=0
        for i in $items
        do
            item=$(tr '[A-Z]' '[a-z]' <<< $i)
            if [ $com == $item ] || [ $com == $counter ]; then
                selectItem=$i
                if [ $language == 'python' ]; then
                    python3.6 ./$language/$selectChapter/$selectItem $image $video
                else
                    g++ -ggdb ./$language/$selectChapter/$selectItem -o runnable `pkg-config --cflags --libs opencv`
                    chmod 777 runnable
                    ./runnable
                    rm runnable
                fi
            fi
            (( counter++ ))
        done
    fi
done