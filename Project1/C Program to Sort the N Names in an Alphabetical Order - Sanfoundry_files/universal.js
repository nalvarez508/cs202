!function(t){var e=t.MailerLiteObject||"ml",n=t[e]||{q:[]};t.ml_storage=t.ml_storage||{};var o=t.ml_storage,i="https://static.mailerlite.com/",a=i+"css/universal.css?v3",s=!1,r=n.q||[];function l(){return l}function c(t,e){return t[e]?t[e]():l}function m(t){return function(){var e=Array.prototype.slice.call(arguments),n=t;return e.forEach(function(t){n=n(t)}),n}}var u={};function f(t){return u[t]=u[t]||{callbacksOnce:[],once:function(t){this.callbacksOnce.push(t)},callbacksEvery:[],every:function(t){this.callbacksEvery.push(t)}},u[t]}var d=function(){return{accounts:function(){return m(function(e){var n=e,o="data-ml-account-"+n+"-suspended";return m(function(e){var s=e;return a&&p(a),m(function e(a){return c({load:function(){return function(t){var e=document.createElement("script");e.src=t,e.async=!0;var n=document.getElementsByTagName("script")[0];n.parentNode.insertBefore(e,n)}(i+"data/a/"+b(n)+"universal/"+s+"_popups.js?v="+Math.floor(Date.now()/1e3)),function e(n){var o=document.getElementsByTagName("*"),i=T||[];(o=Array.prototype.slice.call(o)).forEach(function(o){if((" "+o.className+" ").indexOf(" sqs-blockStatus ")>-1&&"invalid"==o.getAttribute("data-state")&&o.removeAttribute("data-state"),(" "+o.className+" ").indexOf(" open-form-button ")>-1&&(o.onclick=setTimeout(e.bind(null,n))),(" "+o.className+" ").indexOf(" sqs-block-newsletter ")>-1||(" "+o.className+" ").indexOf(" sqs-async-form ")>-1){var a=o.getElementsByTagName("form")[0];if(a&&-1===i.indexOf(a)){var s,r,l;i.push(a);var c=a.getElementsByTagName("input");if([].forEach.call(c,function(t){var e=t.getAttribute("name");"fname"==e?r=t:"lname"==e?l=t:"email"==e&&(s=t)}),s){var m=function(){if(c=s.value,/^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(c)){var e="ml_"+function(){for(var t="",e="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",n=0;n<25;n++)t+=e.charAt(Math.floor(Math.random()*e.length));return t}();t[e]=function(t){},setTimeout(function(){[].forEach.call(a.childNodes,function(t){var e=t.className;"string"==typeof e&&(-1!==e.indexOf("form-submission-text")?t.className="form-submission-text":-1!==e.indexOf("form-submission-html")?t.className="form-submission-html":t.className="hidden "+t.className)})},1e3);var o="&fields[email]="+encodeURIComponent(s.value);r&&r.value&&(o+="&fields[name]="+encodeURIComponent(r.value)),l&&l.value&&(o+="&fields[last_name]="+encodeURIComponent(l.value));var i=document.createElement("script");i.src="https://app.mailerlite.com/webforms/squarespace?callback="+e+"&account_id="+n+o,document.getElementsByTagName("head")[0].appendChild(i)}var c};a.addEventListener?a.addEventListener("submit",m,!1):a.attachEvent&&a.attachEvent("onsubmit",m)}}}})}(n),m(e)},suspend:function(){return document.body.setAttribute(o,"true"),m(e)},webforms:function(){return m(function(e){var a=e;return m(function(e){var s,r,l,u,d=e,y="ml-webforms-popup-"+a,p=!0;function h(){p&&(r.style.display="block"),l.style.visibility="visible",l.style.opacity="1",l.style.left="0",l.style.bottom="0",l.style.top="auto"}function v(){if(r.style.display="none",l.style.visibility="hidden",l.style.position="fixed",l.style.opacity="0",l.style.left="-100%",l.style.bottom="-100%",l.style.top="auto",f(a).callbacksEvery=[],f(a).callbacksOnce=[],f(a).scrollListener&&(t.removeEventListener("scroll",f(a).scrollListener),f(a).scrollListener=!1),-1===["contentPush","slideboxLeft","slideboxRight","barTopRemain","barTop","barBottom"].indexOf(u)){var e=document.body.getAttribute("data-ml-default-overflow");document.body.removeAttribute("data-ml-default-overflow"),document.body.style.overflow=e}if(-1!==["contentPush","barTop"].indexOf(u)){var n=document.body.getAttribute("data-ml-default-position");document.body.removeAttribute("data-ml-default-position"),document.body.style.position=n}}function T(){if(document.body.getAttribute(o))return m(A);N(),-1!==["contentPush","barTop"].indexOf(u)?(l.style.bottom="auto",l.style.position="absolute",r.style.position="absolute"):(l.style.position="fixed",r.style.position="fixed"),-1!==["slideboxRight","slideboxLeft"].indexOf(u)&&(l.style.top="auto",l.style.bottom="0",l.style.width="",g(l,"mailerlite-form-slidebox")),-1!==["slideboxLeft"].indexOf(u)&&(l.style.left="0",l.style.right="auto"),-1!==["slideboxRight"].indexOf(u)&&(l.style.left="auto",l.style.right="0"),-1!==["barBottom"].indexOf(u)&&(l.style.bottom="",l.style.top="auto"),-1!==["barTopRemain","barTop"].indexOf(u)&&(l.style.top=""),p=-1===["contentPush","slideboxLeft","slideboxRight","barTopRemain","barTop","barBottom"].indexOf(u),-1===["contentPush","slideboxLeft","slideboxRight","barTopRemain","barTop","barBottom"].indexOf(u)&&(document.body.setAttribute("data-ml-default-overflow",document.body.style.overflow),document.body.style.overflow="hidden"),-1!==["contentPush","barTop"].indexOf(u)&&(document.body.setAttribute("data-ml-default-position",document.body.style.position),document.body.style.position="static"),(new Image).src="https://track.mailerlite.com/webforms/o/"+a+"/"+d+"?v"+Math.floor(Date.now()/1e3);var e="mailerlite:webform:shown:"+a,n=(new Date).getTime();switch(document.cookie=e+"="+n+"; path=/; expires=Fri, 31 Dec 9999 23:59:59 GMT",u){case"fadeIn":h(),f(a).every(function(e){s=t.innerWidth,i=t.innerHeight,s<768&&e&&"100%"!==e&&(i=Number(e.replace("px",""))),l.style.height=i+"px",l.style.maxHeight=i+"px"}),l.style.opacity=0,setTimeout(function(){g(l,"mailerlite-animation"),setTimeout(function(){l.style.opacity=1,setTimeout(function(){x(l,"mailerlite-animation")},500)},100)},100);break;case"slideIn":f(a).every(function(e){s=t.innerWidth,i=t.innerHeight,s<768&&e&&"100%"!==e&&(i=Number(e.replace("px",""))),l.style.height=i+"px",l.style.maxHeight=i+"px"}),h(),l.style.opacity=0,l.style.bottom="auto",l.style.top="-100%",setTimeout(function(){l.style.opacity=1,g(l,"mailerlite-animation"),setTimeout(function(){l.style.top="0",setTimeout(function(){x(l,"mailerlite-animation"),l.style.top="auto",l.style.bottom="0"},500)},100)},100);break;case"slideboxLeft":f(a).once(function(t){h(),l.style.opacity=0,l.style.left="-500px",l.style.top="auto",f(a).every(function(t){l.style.height=t,l.style.maxHeight=t}),setTimeout(function(){l.style.opacity=1,g(l,"mailerlite-animation"),setTimeout(function(){l.style.left="0px",setTimeout(function(){x(l,"mailerlite-animation")},500)},100)},100)});break;case"slideboxRight":f(a).once(function(t){h(),l.style.opacity=0,l.style.left="auto",l.style.top="auto",l.style.right="-500px",f(a).every(function(t){l.style.height=t,l.style.maxHeight=t}),setTimeout(function(){l.style.opacity=1,g(l,"mailerlite-animation"),setTimeout(function(){l.style.right="0px",setTimeout(function(){x(l,"mailerlite-animation")},500)},100)},100)});break;case"barBottom":f(a).once(function(t){h(),l.style.top="auto";var e="72px";t&&"100%"!==t&&(e=t),l.style.bottom="-"+e,l.style.opacity=0,setTimeout(function(){g(l,"mailerlite-animation"),f(a).every(function(t){l.style.height=t,l.style.maxHeight=t}),setTimeout(function(){l.style.opacity=1,l.style.bottom="0px",setTimeout(function(){x(l,"mailerlite-animation")},500)},100)},100)});break;case"barTopRemain":f(a).once(function(t){var e="72px";t&&"100%"!==t&&(e=t),h(),l.style.bottom="auto",l.style.left="0px",l.style.top="-"+e,setTimeout(function(){g(document.body,"mailerlite-animation"),g(l,"mailerlite-animation"),l.style.top="0px",f(a).every(function(t){var e="72px";t&&"100%"!==t&&(e=t),l.style.height=t,l.style.maxHeight=t,document.body.style.marginTop=e}),setTimeout(function(){x(l,"mailerlite-animation"),x(document.body,"mailerlite-animation")},500)},100)});break;case"barTop":f(a).once(function(e){t.scrollTo(0,0);var n="72px";e&&"100%"!==e&&(n=e),h(),l.style.bottom="auto",l.style.top="-"+n,l.style.left="0px",setTimeout(function(){g(document.body,"mailerlite-animation"),g(l,"mailerlite-animation"),f(a).every(function(t){var e="72px";t&&"100%"!==t&&(e=t),l.style.height=t,l.style.maxHeight=t,document.body.style.marginTop=e}),l.style.top="0px",setTimeout(function(){x(l,"mailerlite-animation"),x(document.body,"mailerlite-animation")},500)},100)});break;case"contentPush":t.scrollTo(0,0),document.body,document.documentElement;var i=t.innerHeight,s=t.innerWidth;f(a).every(function(t){s<768&&t&&"100%"!==t&&(i=Number(t.replace("px","")))}),h(),l.style.height=i+"px",l.style.top="-"+i+"px",setTimeout(function(){g(l,"mailerlite-animation"),g(document.body,"mailerlite-animation"),f(a).every(function(e){s=t.innerWidth,i=t.innerHeight,s<768&&e&&"100%"!==e&&(i=Number(e.replace("px",""))),l.style.height=i+"px",l.style.maxHeight=i+"px",document.body.style.marginTop=i+"px"}),s>=768&&(document.body.style.marginTop=i+"px"),l.style.top="0",setTimeout(function(){x(l,"mailerlite-animation"),x(document.body,"mailerlite-animation")},500),f(a).scrollListener=function(e){t.pageYOffset>=i&&(t.scrollTo(0,t.pageYOffset-i),document.body.style.marginTop="0px",v())},t.addEventListener("scroll",f(a).scrollListener,{once:!0})},100);break;default:h()}return m(A)}function k(){switch(N(),u){case"fadeIn":g(l,"mailerlite-animation"),l.style.opacity="0",setTimeout(function(){v(),x(l,"mailerlite-animation")},500);break;case"slideIn":l.style.bottom="auto",l.style.top="0",setTimeout(function(){g(l,"mailerlite-animation"),l.style.top="-100%",setTimeout(function(){v(),x(l,"mailerlite-animation")},500)},100);break;case"slideboxRight":g(l,"mailerlite-animation"),l.style.right="-500px",setTimeout(function(){v(),x(l,"mailerlite-animation")},500);break;case"slideboxLeft":g(l,"mailerlite-animation"),l.style.left="-500px",setTimeout(function(){v(),x(l,"mailerlite-animation")},500);break;case"barBottom":var e="72px";l.style.height&&"100%"!==l.style.height&&(e=l.style.height),g(l,"mailerlite-animation"),l.style.bottom="-"+e,setTimeout(function(){v(),x(l,"mailerlite-animation")},500);break;case"barTop":f(a).once(function(t){var e="72px";t&&"100%"!==t&&(e=t),g(l,"mailerlite-animation"),g(document.body,"mailerlite-animation"),document.body.style.marginTop="0px",l.style.top="-"+e,setTimeout(function(){v(),x(document.body,"mailerlite-animation"),x(l,"mailerlite-animation")},500)});break;case"barTopRemain":f(a).once(function(t){var e="72px";t&&"100%"!==t&&(e=t),g(l,"mailerlite-animation"),g(document.body,"mailerlite-animation"),document.body.style.marginTop="0px",l.style.top="-"+e,setTimeout(function(){v(),x(document.body,"mailerlite-animation"),x(l,"mailerlite-animation")},500)});break;case"contentPush":g(l,"mailerlite-animation"),g(document.body,"mailerlite-animation"),document.body.style.marginTop="0px";var n=t.innerHeight+"px";l.style.height&&"100%"!==l.style.height&&(n=l.style.height),l.style.top="-"+n,setTimeout(function(){v(),x(l,"mailerlite-animation"),x(document.body,"mailerlite-animation")},500);break;default:v()}return m(A)}function E(){return m(function(t){return u=t,l.setAttribute("animation",u),m(A)})}function w(){return m(function(t){for(;f(a).callbacksOnce.length;)f(a).callbacksOnce.pop()(t);return f(a).callbacksEvery.forEach(function(e){e(t)}),f(a).once=function(e){e(t)},f(a).every=function(e){f(a).callbacksEvery.push(e),e(t)},m(A)})}function N(){if(document.body.getAttribute(o)&&(s=!0),!s){var t=i+"data/a/"+b(n)+"webforms/"+d+"/"+b(a)+"page.html?v="+Math.floor(Date.now()/1e3);r.style.position="fixed",document.body.appendChild(r),l.setAttribute("src",t),l.setAttribute("frameBorder","0"),l.style.position="fixed",l.style.bottom="-100%",l.style.left="-100%",l.style.visibility="hidden",l.style.opacity="0",l.style.right="0",l.style.margin="0",l.style.width="100%",l.style.height="100%",l.style.maxHeight="100%",l.style.zIndex=2147483640,l.style.display="block",document.body.appendChild(l),s=!0}return m(A)}function A(t){return c({animation:E,setHeight:w,show:T,hide:k,load:N},t)}return document.getElementById(y)?(s=!0,r=document.getElementById(y+"-overlay"),l=document.getElementById(y),u=l.getAttribute("animation")||"fadeIn"):(s=!1,r=document.createElement("div"),(l=document.createElement("iframe")).setAttribute("id",y),r.setAttribute("id",y+"-overlay"),r.className="ml-webforms-popup-overlay",u="fadeIn",l.setAttribute("show-overlay","true")),document.onkeydown=function(e){("key"in(e=e||t.event)?"Escape"==e.key:27==e.keyCode)&&k()},m(A)})})}},a)})})})},host:function(){return function(t){return i=t,m(y)}},ecommerce:function(){function e(){return m(function e(n){function o(){return m(function(t){return m(function e(n){return m(function(o){return(new Image).src="https://app.mailerlite.com/shopify/visitor/"+n+"/"+o+"?shop="+t,m(e)})})})}return c({shopify:function(){var n=h("ml_subscriber"),i=h("ml_subscriber_hash"),a=t.location.hostname;return t&&t.Shopify&&t.Shopify.shop&&(a=t.Shopify.shop),n&&i&&o()(a,n,i),m(e)},woocommerce:function(){var n=h("ml_subscriber"),o=h("ml_subscriber_hash"),i=t.location.hostname;return n&&o&&((new Image).src="https://api.mailerlite.com/api/v2/woocommerce/visitor/"+n+"/"+o+"/"+i),m(e)},track:o},n)})}return m(function(t){return c({visitor:e},t)})},css:function(){return function(t){return p(a=t),m(y)}},forms:function(){function t(t){return c({embed:n,onload:e,load:a},t)}function e(){return m(function(t){return form_id=t,o.forms.callbacks[form_id]=o.forms.callbacks[form_id]||[],m(function t(e){return o.forms.callbacks[form_id].push(e),o.forms.htmls[form_id]&&e(o.forms.htmls[form_id]),m(t)})})}function n(){for(var n="ml-form-embed",a=(r=n,document.getElementsByClassName||(document.getElementsByClassName=function(t){var e,n,o,i=document,a=[];if(i.querySelectorAll)return i.querySelectorAll("."+t);if(i.evaluate)for(n=".//*[contains(concat(' ', @class, ' '), ' "+t+" ')]",e=i.evaluate(n,i,null,0,null);o=e.iterateNext();)a.push(o);else for(e=i.getElementsByTagName("*"),n=new RegExp("(^|\\s)"+t+"(\\s|$)"),o=0;o<e.length;o++)n.test(e[o].className)&&a.push(e[o]);return a}),document.getElementsByClassName(r)),s=0;s<a.length;s++)!function(t){var a=t.getAttribute("data-account");if(!a)return!1;var s=a.split(":");if(2!==s.length)return!1;var r=s[0],l=s[1];if(!r||!l)return!1;if(document.body.getAttribute("data-ml-account-"+r+"-suspended"))return!0;var c=t.getAttribute("data-form");if(!c)return!1;var m=c.split(":");if(2!==m.length)return!1;var u=m[0],f=m[1];if(!u||!f)return!1;if(!o.forms.requests[u]){var d=i+"data/a/"+b(r)+"webforms/"+f+"/"+b(u)+"embed.js?v="+Math.floor(Date.now()/1e3),y=document.createElement("script");y.src=d,document.body.appendChild(y),o.forms.requests[u]=!0}e()(u,function(e){setTimeout(function(){if(v(t,n)){t.innerHTML=e;for(var o=t.getElementsByTagName("script"),i=0;i<o.length;i++){var a=o[i],s=document.createElement("script");s.type="text/javascript",a.text&&(s.text=a.text),a.src&&(s.src=a.src),document.getElementsByTagName("body")[0].appendChild(s)}x(t,n)}})})}(a[s]);var r;return m(t)}function a(){return m(function(t){return form_id=t,m(function t(e){var n=e;return o.forms.htmls[form_id]=e,o.forms.callbacks[form_id]&&o.forms.callbacks[form_id].length&&o.forms.callbacks[form_id].forEach(function(t){t(n)}),m(t)})})}return o.forms=o.forms||{},o.forms.callbacks=o.forms.callbacks||{},o.forms.htmls=o.forms.htmls||{},o.forms.requests=o.forms.requests||{},m(t)}}}();function y(t){return c({accounts:d.accounts,css:d.css,forms:d.forms,host:d.host,ecommerce:d.ecommerce},t)}function p(t){if(!s){var e=document.getElementsByTagName("head")[0],n=document.createElement("link");n.rel="stylesheet",n.type="text/css",n.href=t,n.media="all",e.appendChild(n),s=!0}}function b(t){return Math.floor(t/1e3)+"/"+t+"/"}function h(t){return decodeURIComponent((new RegExp("[?|&]"+t+"=([^&;]+?)(&|#|;|$)").exec(location.search)||[null,""])[1].replace(/\+/g,"%20"))||null}function v(t,e){return t.classList?t.classList.contains(e):-1<t.className.indexOf(e)}function g(t,e){if(t.classList)t.classList.add(e);else if(!v(t,e)){var n=t.className.split(" ");n.push(e),t.className=n.join(" ")}return t}function x(t,e){if(t.classList)t.classList.remove(e);else{var n=t.className.split(" ");n.splice(n.indexOf(e),1),t.className=n.join(" ")}return t}!function t(e,n){e.forEach(function(e){var o=m(n).apply(null,e.a);e.q&&t(e.q,o)}),e.push=function(){var t=Array.prototype.slice.call(arguments[0].a||[]);return n.apply(null,t)}}(r,y),n=t[e]=m(y),t&&t.Shopify&&t.Shopify.shop&&n("ecommerce","visitor","shopify"),n("forms","embed"),setTimeout(function(){n("forms","embed")},500),setTimeout(function(){n("forms","embed")},1e3),t.addEventListener("message",function(t){if(t&&t.data&&"string"==typeof t.data){var e=t.data.split("-");e.length>1&&"ml"==e[0]&&n.apply(null,e.slice(1))}},!1);var T=[]}(window);